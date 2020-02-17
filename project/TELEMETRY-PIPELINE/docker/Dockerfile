# How to build? 
# 
# docker build -f ./Dockerfile -t pipeline:<version>
# 
# How to Run? 
# docker run -d --net=host [--volume <local>:/data] \
# 	--name pipeline pipeline:<version>
#
# command line option --volume is optional. without it
# default config which terminates tcp streams in :5432, and dumps 
# to /data/dump.txt will be setup. For any real deployment, a pipeline.conf
# should be provided, so volume should be mounted. If the /data
# volume is mapped locally, the directory must contain the pipeline.conf 
# to use. If you need to debug, add the following options at 
# the end of run. 
# 
# -debug -log=/data/pipeline.log -config=/data/pipeline.conf
# 
# How to delete? 
# 
# docker rm -v -f pipeline
#
# You can run "docker inspect pipeline" and find the mount point where you can
# inspect them. 
#
# ================================================================================  

FROM debian:stable-slim 

MAINTAINER Santosh K Padhy <sanpadh2@cisco.com>

# Stage default configuration, metrics spec and example setup 
ADD pipeline.conf /data/pipeline.conf 
ADD metrics.json /data/metrics.json 
ADD metrics_gpb.json /data/metrics_gpb.json
ADD pipeline /pipeline


VOLUME ["/data"]

WORKDIR /
ENTRYPOINT ["/pipeline"]
CMD ["-log=/data/pipeline.log", "-config=/data/pipeline.conf"]
