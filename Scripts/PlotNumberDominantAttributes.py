# File         : Scripts/PlotsNumberDominantAttributes.py

## Description : A script for plotting the CCDF of the number of 
##               attributes from the data sets outputted by the 
##               simulator.

import matplotlib.pyplot as plt
import numpy             as np
import csv

def PlotNumberDominantAttributes( AS, WhichOrders ):

    if( WhichOrders == "All" ):
        
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

    x       = []
    y       = []
    labels  = []

    for i, Order in enumerate( Orders ):
        
        NumDom = []

        fileNameResults = "OutputDataSets/Rocketfuel/%s/%s/Stable_State.tsv" % ( AS, Order )

        print ( "\t+ Reading data set from '%s'\n" % fileNameResults )

        with open( fileNameResults ) as file:

            fileCSV = csv.reader( file, delimiter='\t')

            for numberRow, row in enumerate( fileCSV ):
                if( numberRow != 0 ):
                    for numberColumn, column in enumerate( row ):
                        if( numberColumn != 0 ):
                            NumDom.append( column.count( '(' ) )

        AvgNumDom  = sum( NumDom ) / float( len( NumDom ) )
        NumDomBins = np.bincount( NumDom )

        Ccdf = 1 - np.divide( np.cumsum( NumDomBins ), np.sum( NumDomBins ), dtype = np.float32 )

        x.append( np.arange( 0.5, Ccdf.size-1 ) )
        y.append( Ccdf[1:] )

        labels.append( Label[i] + '(%.1f)' % AvgNumDom )

    plt.bar( x[0] - 0.375 , y[0], width = 0.2, color = Color[0] )
    plt.bar( x[1] - 0.125 , y[1], width = 0.2, color = Color[1] )
    plt.bar( x[2] + 0.125 , y[2], width = 0.2, color = Color[2] )
    plt.bar( x[3] + 0.375 , y[3], width = 0.2, color = Color[3] )

    plt.legend( labels,                                 fontsize  = 12 , handlelength = 0.85 )

    plt.xlabel( "Number of dominant attributes",        fontsize  = 15 , labelpad     = 10   )
    plt.xticks( np.arange( 0.5, 7 ), np.arange( 1, 8 ), fontsize  = 15 )
    plt.xlim( 0, 7 )

    ax = plt.gca()
    ax.xaxis.set_label_coords(0.5, -0.1)

    plt.ylabel( "CCDF",                                 fontsize  = 16, labelpad = 10   )
    plt.yticks(                                         fontsize  = 16                  )
    plt.ylim( 0, 1 )

    plt.tight_layout()
    plt.grid( True, which = "both" )

    fileNamePlot = "Plots/%s_NumberDominantAttributes.pdf" % AS
    print ( "\t+ Saving Plot to File '%s' "  % fileNamePlot )

    plt.savefig( fileNamePlot )
    plt.close()

print ( " \n--- Plotting the Distribution of Number of Dominant Attributes \n " )

## Change to "AS1239" to obtains the plots presented in Section 6

PlotNumberDominantAttributes( "AS3967", "All" )
