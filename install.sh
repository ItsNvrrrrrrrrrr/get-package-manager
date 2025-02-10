#!/bin/bash

set -e

echo "Compiling GET Package Manager..."
make

echo "Moving binary to /home/$(whoami)/.local/bin/"
mkdir -p /home/$(whoami)/.local/bin/
mv get /home/$(whoami)/.local/bin/

echo "Exporting path..."
echo 'export PATH="$HOME/.local/bin:$PATH"' >> ~/.bashrc
source ~/.bashrc

echo "Installation complete! You can now use 'get' command."
