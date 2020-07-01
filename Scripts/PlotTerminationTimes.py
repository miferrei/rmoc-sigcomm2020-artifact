# File : Scripts/PlotsTerminationTimes.py

## Description : A script for plotting the CCDF of the termination 
##               times from the data sets outputted by the simulator.

import matplotlib.pyplot   as plt
import numpy as np
import sys

def PlotTerminationTimes( AS, Metric, WhichOrder, Event ):

    if( WhichOrder == "All" ):
        
        Orders  =  [    "HopsLength/ProductOrderHopsLengths"            , 
                        "WidthHops/ProductOrderWidthHops"               ,            
                        "WidthLength/ProductOrderWidthLengths"          , 
                        "WidthHopsLength/ProductOrderWidthHopsLengths"  ]

        Color   =   {   0 : 'black'                                     ,
                        1 : 'red'                                       ,
                        2 : 'green'                                     ,
                        3 : 'blue'                                      }

        Label   =   {   0 : 'Hops-lengths   '                           ,
                        1 : 'Width-hops      '                          ,
                        2 : 'Width-lengths  '                           ,
                        3 : 'Width-hops- \n lengths           '         }   

    if ( WhichOrder == "WidthLengthsOrders" ):
    
        Orders  =   [   "WidthLength/WidestShortestOrder"               , 
                        "WidthLength/ShortestWidestOrder"               , 
                        "WidthLength/ProductOrderWidthLengths"          ]   

        Color   =   {   0 : 'lime'                                      ,
                        1 : 'darkviolet'                                ,
                        2 : 'green'                                     }

                                    
        Label   =   {   0 : 'Widest-shortest \n order              '    ,
                        1 : 'Shortest-widest \n order              '    ,
                        2 : 'Product order on \n width-lengths '        }

    labels = []

    for i, Order in enumerate( Orders ):

        if( Metric == "Termination_Times" ):
            fileNameResults = "OutputDataSets/Rocketfuel/%s/%s/%s_%s.tsv" % ( AS, Order, Metric, Event )
        else:
            fileNameResults = "OutputDataSets/Rocketfuel/%s/%s/%s.tsv"    % ( AS, Order, Metric )

        print ( "\t+ Reading data sets from '%s'\n" % fileNameResults )

        with open ( fileNameResults ) as file:

            terminationTimes = np.genfromtxt( file, delimiter='\t', dtype = np.float32 )

            terminationTimes = np.delete( terminationTimes, 0, 0 )
            terminationTimes = np.delete( terminationTimes, 0, 1 )

            terminationTimes = terminationTimes.flatten()
            terminationTimes.sort()

            CCDF = np.zeros( shape = terminationTimes.shape , 
                             dtype = np.float32             )
            for j in range( terminationTimes.size ):
                CCDF[j] = 1.0 - float(j) / CCDF.size

            x = terminationTimes
            y = CCDF

            plt.plot( x, y, drawstyle='steps-post', linewidth = 4, color = Color[ i ] )

            labels.append( Label[ i ] + '(%.1f ms)' % np.mean(x) )

    plt.legend( labels,                          handlelength = 0.85,   fontsize = 10 )

    if( Metric == "Termination_Times" ):
        plt.xlabel( "Termination time (ms)",                    labelpad = 10,         fontsize = 14 )
    if( Metric == "Times_Propagate_Unreachability" ):
        plt.xlabel( "Time to Propagate Unreachability (ms)",    labelpad = 10,         fontsize = 14 )

    plt.xticks(                                                                        fontsize = 14 )
    plt.xlim( 0, 18 )

    ax = plt.gca()
    ax.xaxis.set_label_coords(0.5, -0.1)

    plt.ylabel( "CCDF",                                         labelpad = 10,         fontsize = 14 )
    plt.yticks(                                                                        fontsize = 14 )
    plt.ylim( 0, 1  )

    plt.tight_layout()
    plt.grid( True, which = "both" )

    if( Metric == "Termination_Times" ):
        fileNamePlot = "Plots/%s_%s_%s_%s.pdf" % ( AS, Metric, WhichOrder, Event )
    else:
        fileNamePlot = "Plots/%s_%s.pdf"       % ( AS, Metric )        
    print  ( "\t+ Saving plot to '%s'\n" % fileNamePlot )
   
    plt.savefig( fileNamePlot )
    plt.close()

print ( " \n--- Plotting the Distributions of Termination Times --------\n " )

## Change to "AS1239" to obtains the plots presented in Section 6

PlotTerminationTimes( "AS3967", "Termination_Times",               "All",                  "Announcement"    )
PlotTerminationTimes( "AS3967", "Termination_Times",               "All",                  "Failure"         )
PlotTerminationTimes( "AS3967", "Termination_Times",               "WidthLengthsOrders",   "Announcement"    )
PlotTerminationTimes( "AS3967", "Termination_Times",               "WidthLengthsOrders",   "Failure"         )
PlotTerminationTimes( "AS3967", "Times_Propagate_Unreachability",  "All",                  "Failure"         )
                        
