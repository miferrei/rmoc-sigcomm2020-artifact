# Artifact of the paper "Routing on Multiple Optimality Criteria"

## Table of Contents 

  - Introduction
  - Download and Installation
  - Basic Simulator Usage
  - Small-Scale Evaluation

## 1. Introduction

  Our artifact consists of a simple simulator for dominant-paths vectoring protocols, both non-restarting and restarting versions, and the scripts for: (1) transforming [Rocketfuel topologies](https://research.cs.washington.edu/networking/rocketfuel/papers/sigcomm2002.pdf) into network data sets that serve as input to the simulator; and (2) generating plots with CCDFs for the number of dominant attributes and for the termination times of dominant-paths vectoring protocols from the data sets that are output by the simulator. The simulator is implemented in *C++17* and is compiled with *GCC 4.2.1*. It requires the *boost* library. The scripts are written in *Python 3.8*. They require the *networkx*, *numpy* and *matplotlib* libraries.
  
  In addition to the artifact, the present documentation contains: (1) a description of how the simulator is used; and (2) a workflow that produces a small-scale evaluation of dominant-paths vectoring protocols. 
  
  The repository containing the artifact is structured as follows. 
  
  * **RockerfuelTopologies**: The Rocketfuel topologies as downloaded from the [Rocketfuel Project](https://research.cs.washington.edu/networking/rocketfuel);

  * **Scripts**: The scripts;
  
  * **NetworkDataSets**: The network data sets generated from the Rocketfuel topologies;
  
  * **Simulator**: The source code of the simulator;
  
  * **OutputDataSets**: The data sets output by the simulator and from which the plots presented in Section 6 of the paper are produced;
  
  * **Plots**: The plots presented in Section 6 of the paper. 
    
## 2. Download and Installation

Our artifact is packaged in a [Docker](https://docs.docker.com) image. We show how to download and install the artifact in your local machine.
 
  1. Make sure you have Docker installed in your machine. (If you do not, then please refer to https://docs.docker.com/get-docker/.)
  
  2. Download the artifact to your local machine:
      ```
      git clone https://github.com/miferrei/rmoc-sigcomm2020-artifact.git
     ```
     and then step into the directory containing the artifact:
     ```
     cd rmoc-sigcomm2020-artifact
     ```
      
  3. Build the Docker image: 
      ```
      sudo docker build --tag rmoc-sigcomm2020-artifact:1.0 .
      ```
     This step will take about five minutes. 
  
  4. Create an interactive terminal with a local volume available in the Docker container:
      ```
      sudo docker run -v $(pwd):/root --name rmoc -it rmoc-sigcomm2020-artifact bash
      ```
      
  5. Later, to erase the artifact, first remove the Docker container and the local volume:
      ```
      sudo docker rm -v rmoc 
      ``` 
      and then the Docker image:
      ```
      sudo docker rmi rmoc-sigcomm2020-artifact:1.0 
      ``` 
      
## 3. Basic Simulator Usage

We show how to use the programs that simulate dominant-paths vectoring protocols. 

(See Section 4 of the paper for the specification of dominant-paths vectoring protocols.)

  ### 3.1. Simulation of Non-Restarting Protocols
   
  #### 3.1.1. Description
   
   The program *Simulator/Main/SimulateNonRestartingProtocol.cpp* simulates a non-restarting protocol operating on a given partial or total order on attributes in a given network. Specifically, it simulates (1): the network-wide announcement of a destination, for all possible destinations; and then (2) the failure of a link, for all possible link failures. All simulations foresee a given number of independent trials. 
  
  #### 3.1.2. Usage 
   
  The simulator is invoked with the following command:
      
      ./Simulator/Main/SimulateNonRestartingProtocol -o ORDER -n NETWORK_DATA_SET -r R 
      
   where: 
   
   * *ORDER* is the identifier of the partial or total order;
   
   * *NETWORK_DATA_SET* is a network data set; 
   
   * *R* is the number of independent trials.
   
   (See the next section of the documentation.)
  
   #### 3.1.3. Inputs
    
   * *ORDER* is one the following identifiers:
   
      (Partial orders)
      * *"ProductOrderHopsLengths"* : The product order on pairs hops-length;
      * *"ProductOrderWidthHops"* : The product order on pairs width-hop;
      * *"ProductOrderWidthLengths"* : The product order on pairs width-length;
      * *"ProductOrderWidthHopsLengths"* : The product order on triples width-hops-length;
            
      (Total orders)
      * *"ShortestWidestOrder"* : The shortest-widest order on pairs width-length;
      * *"WidestShortestOrder"* : The widest-shortest order on pairs width-length.
   
   (See Section 2 of the paper for the definition of the above partial and total orders.)
         
   * *NETWORK_DATA_SET* is a file of tab-separated values under directory *NetworkDataSets/*. This file has the following format:
   
      ```
      V
      u1   u2   a1   a2  (a3) 
      .    .    .    .    (.)
      .    .    .    .    (.)
      .    .    .    .    (.) 
      ``` 
   
     The first line represents the number `V` of nodes in the network. Every other line represents a link from node `u1` to a node `u2` with attribute `(a1, a2)`     or `(a1, a2, a3)`. When the link attribute is `(a1, a2)`:
     
     * If `(a1, a2)` is a pair hops-length, then `a1` is '1' and `a2` is a length;
     * If `(a1, a2)` is a pair width-hops, then `a1` is a width and `a2` is '1';
     * If `(a1, a2)` is a pair width-length, then `a1` is a width and `a2` is a length.
          
     When the link attribute is a triple width-hops-length `(a1, a2, a3)`: 
     
     * `a1` is a width, `a2` is '1' and `a3` is a length.
  
   * *R* is an integer between `0` and `2^31-1`.

   #### 3.1.4. Outputs
   
   * *STABLE_STATE*. A file of tab-separated values under directory *OutputDataSets/*. The file stores a matrix with `V` rows and `V` columns where the entry at row `s` and column `t` contains the elected attributes at `s` to reach `t` in stable state.
   
   * *TERMINATION_TIMES_ANNOUNCEMENT*. A file of tab-separated values under directory *OutputDataSets/*. The file stores a matrix with `R` rows and `V` columns where the entry at row `r` and column `t` contains the termination time following the network-wide announcement of destination `t` in the `r`th trial. 
    
   * *TERMINATION_TIMES_FAILURE*. A file of tab-separated values under directory *OutputDataSets/*. Let `E` be the number of links in the network. The file stores a matrix with `R` rows and `E` columns where the entry at row `r` and column `e` contains the termination time following the failure of link `e` in the `r`th trial. 

  ### 3.2. Simulation of Restarting Protocols
  
  #### 3.2.1. Description 

  The program *Simulator/Main/SimulateRestartingProtocol.cpp* simulates computation instances of a restarting protocol operating on a given isotone partial or total order on attributes in a given network. More concretely, it simulates the failure of a link, for all possible link failures. All these simulations foresee a given number of independent trials. (Since every computation instance of the restarting protocol pertaining to a given destination behaves as a network-wide announcement of this destination in the non-restarting protocol, the stable state and termination times of the protocol can be obtained with the simulator described in Section 3.1 of the documentation.)
  
  (See Section 3.1 of the paper for the definition of isotonicity of a partial or total order on attributes.)
  
   #### 3.2.2. Usage 
   
   The simulator is invoked with the following command:
      
      ./Simulator/Main/SimulateRestartingProtocol -o ORDER -n NETWORK_DATA_SET -r R 
      
   where: 
   
   * *ORDER* is the identifier of the isotone partial or total order;
   
   * *NETWORK_DATA_SET* is a network data set; 
   
   * *R* is the number of independent trials of simulations following the failure of a link.

   #### 3.2.3. Inputs 

   * *ORDER* is as in Section 3.1.3 of the documentation, except for the identifier *"ShortestWidestOrder"* -- the shortest-widest order on pairs width-length, which this version of the protocol does not support. 
  
   * *NETWORK_DATA_SET* is as in Section 3.1.3.
  
   * *R* is as in as in Section 3.1.3.
   
   #### 3.2.4. Outputs
  
   * *TIMES_PROPAGATE_UNREACHABILITY*. A file of tab-separated values under directory *OutputDataSets/*. The file stores a matrix with `R` rows and `E` columns where the entry at row `r` and column `e` contains the time to propagate unreachability following the failure of link `e` in the `r`th trail. 

## 4. Small-Scale Evaluation 

The evaluation of dominant-paths vectoring protocols presented in Section 6 of the paper focuses on the largest Rocketfuel topology, which is AS 1239. However, the time required to carry out simulations in this network is deemed too large for testing. Therefore, for the purpose of this review, we consider an evaluation based on a smaller Rocketfuel network, AS 3967, and on a fewer number of independent trials for each network event, 10. The results in AS 1239 and in AS 3967 are qualitatively the same. 

We provide a workflow that: (1) generates the network data sets pertaining to AS 3967; (2) executes simulations of dominant-paths vectoring protocols; and (3) produces plots with CCDFs of the number of dominant attributes and the termination times from the data sets output by the simulator. 

  1. The workflow is invoked with the following command:
  
      ```
      bash run-SmallScaleEvaluation.sh
      ```
      
  Its execution time is approximately 1.5 hour. 
  
  2. The plots produced can be found under directory *Plots/*, alongside those presented in Section 6 of the paper.
 
## Authors 

  * Miguel Alves Ferreira, with *Instituto de Telecomunicações, Instituto Superior Técnico, Universidade de Lisboa*;

  * João Luís Sobrinho, with *Instituto de Telecomunicações, Instituto Superior Técnico, Universidade de Lisboa*.

