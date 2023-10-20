#!/bin/bash

# echo "single line comment: #"

######################################
## echo "mutil line comment: #"     ##
## echo "mutil line comment: #"     ##
## echo "mutil line comment: #"     ##
######################################

: '
echo "mutil line comment: : ' '" 
echo "mutil line comment: : ' '" 
echo "mutil line comment: : ' '" 
'

<<COMMENT
echo "mutil line comment: <<COMMENT COMMENT" 
echo "mutil line comment: <<COMMENT COMMENT" 
echo "mutil line comment: <<COMMENT COMMENT" 
COMMENT

echo "no comment" 
