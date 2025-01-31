#!/bin/bash
#------------------------------------------------------
# Export Settings
#------------------------------------------------------
SCRIPT_DIR="$(dirname $(readlink -f $0))"
SIZES=($(( 2**0 )) $(( 2**10 )) $(( 2**19 )) $(( 2**20 )) $(( 2**21 )) $(( 2**22 )) $(( 2**23 )) $(( 2**24 )) $(( 2**25 )))
CONTAINER=anyblob-data
if [[ -z "${REGION}" ]]; then
    export REGION=eu-central-1
else
    CONTAINER=anyblob-data-${REGION}
fi
#------------------------------------------------------
aws s3api create-bucket --bucket $CONTAINER --region $REGION --create-bucket-configuration LocationConstraint=$REGION
#------------------------------------------------------
for size in ${SIZES[@]}
do
    for n in {1..8192}
    do
        openssl rand -out ${n}.bin $size
        aws s3 cp ${n}.bin s3://${CONTAINER}/${size}/${n}.bin
        openssl enc -aes-256-cbc -K "3031323334353637383930313233343536373839303132333435363738393031" -iv "30313233343536373839303132333435" -in ${n}.bin -out ${n}.enc.bin
        aws s3 cp ${n}.enc.bin s3://${CONTAINER}/enc/${size}/${n}.bin
        rm ${n}.bin
        rm ${n}.enc.bin
    done
done
#------------------------------------------------------
