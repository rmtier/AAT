############################
# init script 
# 
# author: Rami Mtier
# date:   9.5.2016
#############################
# config
VIRTUAL_MACHINE_NAME="vm"
PROXY_NAME="proxy"
PROXY_CONTAINER_NAME="nginx"
VIRTUALIZATION=false
AAT_NODE_CONTAINER="node"
AAT_CONTAINER_NAME="aat"
NUMBER_OF_AAT_CONTAINERS=1
############################
# arguments
while (( "$#" ));
do
    PARAM="$1";
    VALUE="$2";
    case $PARAM in
	-v)     
		VIRTUALIZATION=true
		;;
    esac	
    shift
done
#############################

if [ $VIRTUALIZATION == true ]; then

	docker-machine create -d virtualbox $VIRTUAL_MACHINE_NAME

	#change enviroment to virtual machine
	eval $(docker-machine env $VIRTUAL_MACHINE_NAME)
fi

#proxy container
docker build -t $PROXY_CONTAINER_NAME /nginx/
docker run -itd -p 80:80 --name=$PROXY_NAME $PROXY_CONTAINER_NAME

#rails containers 
docker build -t $AAT_NODE_CONTAINER /AAT_server_app/

for i in `seq 1 $NUMBER_OF_AAT_CONTAINERS`; do
	docker run -itd -p 8080:3000 --name=$AAT_CONTAINER_NAME$NUMBER_OF_ATT_CONTAINERS $AAT_NODE_CONTAINER 
done
