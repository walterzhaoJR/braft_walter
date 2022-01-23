#!/bin/bash

# source shflags from current directory
mydir="${BASH_SOURCE%/*}"
if [[ ! -d "$mydir" ]]; then mydir="$PWD"; fi
. $mydir/../../shflags

DEFINE_integer port 8100 "Port of the first server"

goal=$1

ps -ef|grep add_server|grep $((${FLAGS_port}+${goal}))|awk '{print $2}'|xargs kill -9