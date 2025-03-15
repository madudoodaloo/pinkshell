#!/bin/bash

# Run make re
make re

# Check if make re was successful
if [ $? -eq 0 ]; then
    # Run the minishell program
    ./minishell
else
    echo "make re failed. Exiting."
    exit 1
fi
