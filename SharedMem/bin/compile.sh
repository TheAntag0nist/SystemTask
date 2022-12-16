# Move to root directory
cd ..
# Compile programs
gcc server.c global/global.c -o server
gcc client.c global/global.c -o client
# Move programs to /bin
mv server ./bin/server
mv client ./bin/client
