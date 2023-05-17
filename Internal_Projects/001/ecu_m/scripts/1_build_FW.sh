
HOME_PATH="/home/gaviolam"
WORKSPACE_PATH="linux_kernel_src/kirkstone_4.0/poky"

cd ${HOME_PATH}/${WORKSPACE_PATH}
source oe-init-build-env
echo "Building kernel image"
bitbake core-image-minimal-dev
echo "Build finished"
