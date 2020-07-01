## File        : Scripts/NetworkDataSets.py

## Description : A script for transforming Rocketfuel topologies into the
##               network data sets that serve as input to the simulator.

# Public Library
import networkx as nx
import os
import sys
import re

## Change to:
##   'for AS in ['1221', '1239', '1755', '3257', '3967', '6461']:
## to generate the test networks pertaining the all the ASs.

AS = "AS3967"

fileNameWeights   = 'RocketfuelTopologies/%s/weights.intra'   % AS
fileNameLatencies = 'RocketfuelTopologies/%s/latencies.intra' % AS

graph = nx.Graph()

with open( fileNameWeights ) as fileWeight, open( fileNameLatencies ) as fileLatencies: 
  
    pattern = '[0-9]'

    for lineWeight, lineLatencies in zip(fileWeight, fileLatencies):
 
        argsWeight    = lineWeight.rstrip().split(" ")
        argsLatencies = lineLatencies.rstrip().split(" ")

        node1  = argsWeight[0]
        node2  = argsWeight[1]

        width  = int( 100 * (1 / float( argsWeight[2] ) ) )  
        length = int( float( argsLatencies[2] ) )          

        graph.add_edge( node1, node2, Width = width, Length = length )

graph = max( ( graph.subgraph( c ) for c in nx.biconnected_components( graph ) ), key = len )
graph = nx.convert_node_labels_to_integers( graph )
graph = graph.to_directed()

print ( "\n--- Test Network pertaining to %s" % AS )
print ( "\tNumber of Nodes: %d" % graph.number_of_nodes() )
print ( "\tNumber of Links: %d" % graph.number_of_edges() )
print ( "\tNumber of Distinct Widths: %d"  % len( set([ width for _, _, width in graph.edges.data('Width') ]) ) )

for Attribute in [ ['Hops' , 'Length'], ['Width', 'Hops'], ['Width', 'Length'], ['Width', 'Hops', 'Length'] ]:

    dirNameTestNetwork   = "NetworkDataSets/Rocketfuel/%s" % ( AS )
    fileNameTestNetwork  = "%s/%s.tsv" % ( dirNameTestNetwork, ''.join(Attribute) )

    try:
        os.makedirs( dirNameTestNetwork )
    except OSError as exception:
        pass

    fileTestNetwork     = open ( fileNameTestNetwork, "w+" )

    print ( "\n\t+ Saving Data Set to File '%s' " % fileNameTestNetwork )

    string2file = '%s\n' % str( graph.number_of_nodes() )
    fileTestNetwork.write( string2file )

    for u, v, data in graph.edges( data = True ):
    	
        string2file  = '%s\t%s' % ( str(u), str(v) )

        if( 'Width'  in Attribute ):
            string2file += '\t%s' % str( data['Width'] )

        if( 'Hops'   in Attribute ):
            string2file += '\t%s' % '1'

        if( 'Length' in Attribute ):
            string2file += '\t%s' % str( data['Length'] )

        string2file += '\n'

        fileTestNetwork.write( string2file )

    fileTestNetwork.close()

print ( "" )


