FROM ubuntu:focal
ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get --quiet update \
 && apt-get install --quiet --yes --no-install-recommends \
                       tzdata           \
                       python3.8        \
                       python3-pip    	\
                       make             \
                       g++              \
                       libboost-all-dev \
 && apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

RUN pip3 install networkx matplotlib numpy

RUN         cd  /root 

WORKDIR     /root/
