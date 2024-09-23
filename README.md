# Client Server Instructions
## How to Run the Program

* Note --> English is not my first language, but I will try my best to
use simple words and make it as understandable as possible*

### Files to download

- server
- client.c
- makefile
---
### CSE GRID
 - Step 1 --> Store all the files that you downloaded in one singular folder/directory in your computer.
    -  Using WIN SCP (for windows) put this file/directory in the CSE GRID.
 - Step 2 --> Log into CSE grid using your command prompt or PUTTY (for the sake of this assignment I am using my command prompt)
    - Once in CMD screen go ahead and press <ctrl+shift+2> or open one more screen (for cmd prompt).
    - You will need two screens for the purpose of running server and client
    -  **LOG IN TO CSE GRID**
       - In your Command prompt type in the following

         `ssh <username>@csegrid.ucdenver.pvt`
    - Type in your password. 
    - Do this for both the cmd screens.
    - Type in the following one after another for both the screens:

      1. `pwd`
      2. `ls` --> choose the directory in which you have saved your server, client and makefile.
      3. `cd <folder/directory name>`

### Server SIDE
Type the following: 
- `hostname` **This gives you the name of the hostname you are in.** *ex: csci-gnode-xx (xx will range from 01 to 04)*
- `host <csci-gnode-xx>` *Replace the xx with the number displayed on your cmd screen* **This gives you the IP Address for your host. (Where you are running your server)**
- `chmod a+x server` **This allows you to use the server file as an executable on CSE GRID.**
- `./server <portnumber>` **Your server should be up and running.**

   Server Side Screen:
![Server Side Screen](https://media.discordapp.net/attachments/1121889499459358783/1212644814215192618/image.png?ex=65f2967d&is=65e0217d&hm=3f66340322fc8258a2cc56a7dfb990b30fb99d86634e15eddce530b1748dabf6&=&format=webp&quality=lossless&width=1280&height=700)
> Since certain port numbers are reserved, just FYI while testing, I used 2999 and 1901 ports which worked just fine.
---
> Note: Keep note of the server IP address and the port number used since we'll be passing those as arguments from client side.
---
### Client SIDE
Type the following:
- `make client` **This allows you to use the client file as an executable on CSE GRID.**
- `./client <server IP address> <portnumber>` **After you pass in the IP address and port number, your client should be connected to server and ask you for a string.**
- **A prompt asking for a string input should appear. Type in a string of max 255 characters.**
- **After that, you'll be able to see the server response and the size of the string provided by the server.**

   Client Side Screen:
![Client Side Screen](https://media.discordapp.net/attachments/1121889499459358783/1212644910339989544/image.png?ex=65f29694&is=65e02194&hm=f9fd0930034b66845ed54edbf09c732e2f260042d428f8473b073047efd7ea68&=&format=webp&quality=lossless&width=1280&height=700)

