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
docker build -t $PROXY_CONTAINER_NAME -name "$PROXY_NAME" 
docker run -itd -p 80:80 --name=$PROXY_NAME $PROXY_CONTAINER_NAME $PROXY_CONTAINER_NAME
