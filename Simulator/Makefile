
CC         := g++
CCFLAGS    := -Wall -std=c++17
INCLUDES   := -I Headers

VPATH  	   := Sources/Main
VPATH 	   += Sources/Graphs
VPATH 	   += Sources/DataStructures
VPATH 	   += Sources/DominantPathsProtocols/NonRestartingProtocol 
VPATH 	   += Sources/DominantPathsProtocols/RestartingProtocol 

all: SimulateNonRestartingProtocol SimulateRestartingProtocol 

Objects/%.o: 	  %.cpp 
	@mkdir -p Objects
	@echo Compiling binary $@
	@$(CC) -c $(CCFLAGS) $(INCLUDES) -o $@ $<
	@echo Success

SimulateNonRestartingProtocol: Objects/SimulateNonRestartingProtocol.o Objects/NonRestartingRoutingSimulator.o Objects/NonRestartingProtocolCode.o Objects/NonRestartingRoutingState.o Objects/RestartingRoutingSimulator.o Objects/RestartingProtocolCode.o Objects/RestartingRoutingState.o Objects/AugmentedPriorityQueue.o Objects/PriorityQueue.o Objects/Graphs.o
	@mkdir -p Executables
	@echo Linking to executable $@	
	@$(CC) $^ $(CCFLAGS) $(LFLAGS) -o Executables/$@
	@echo Success

SimulateRestartingProtocol: Objects/SimulateRestartingProtocol.o Objects/RestartingRoutingSimulator.o Objects/RestartingProtocolCode.o  Objects/RestartingRoutingState.o  Objects/NonRestartingRoutingSimulator.o Objects/NonRestartingProtocolCode.o Objects/NonRestartingRoutingState.o Objects/AugmentedPriorityQueue.o Objects/PriorityQueue.o Objects/Graphs.o
	@mkdir -p Executables
	@echo Linking to executable $@	
	@$(CC) $^ $(CCFLAGS) $(LFLAGS) -o Executables/$@
	@echo Success

clean:			  
	@rm -rf Objects Executables
	@echo Success
