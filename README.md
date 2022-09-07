# Docker
Docker is a set of platform as a service products that use OS-level virtualization to deliver software in packages called containers. The service has both free and premium tiers. The software that hosts the containers is called Docker Engine. It was first started in 2013 and is developed by Docker, Inc.

## Download and install Docker
In this section, I'll walk you through how to intall docker on windows and build image, run, push to dockerhub registery.

### Docker Desktop WSL 2 backend

Windows Subsystem for Linux (WSL) 2 introduces a significant architectural change as it is a full Linux kernel built by Microsoft, allowing Linux distributions to run without having to manage Virtual Machines. With Docker Desktop running on WSL 2, users can leverage Linux workspaces and avoid having to maintain both Linux and Windows build scripts. In addition, WSL 2 provides improvements to file system sharing, boot time, and allows access to some cool new features for Docker Desktop users.

Docker Desktop uses the dynamic memory allocation feature in WSL 2 to greatly improve the resource consumption. This means, Docker Desktop only uses the required amount of CPU and memory resources it needs, while enabling CPU and memory-intensive tasks such as building a container to run much faster.

Additionally, with WSL 2, the time required to start a Docker daemon after a cold start is significantly faster. It takes less than 10 seconds to start the Docker daemon when compared to almost a minute in the previous version of Docker Desktop.



Follow along https://docs.docker.com/desktop/windows/wsl/



## Docker container


a container is simply another process on your machine that has been isolated from all other processes on the host machine. That isolation leverages kernel namespaces and cgroups, features that have been in Linux for a long time. Docker has worked to make these capabilities approachable and easy to use.


So, containers have to fulfill four major requirements to be acceptable as such:
Not negotiable: They have to run on a single host. Okay, so two computers cannot run a single container.
Clearly: They are groups of processes. You might know that Linux processes live inside a tree structure, so we can say containers must have a root process.
Okay: They need to be isolated, whatever this means in detail.
Not so clear: They have to fulfill common features. Features in general seem to change over time, so we have to point out what the most common features are.
 
 	










## Docker image

What is a container image?¶
When running a container, it uses an isolated filesystem. This custom filesystem is provided by a container image. Since the image contains the container's filesystem, it must contain everything needed to run an application - all dependencies, configuration, scripts, binaries, etc. The image also contains other configuration for the container, such as environment variables, a default command to run, and other metadata.



## Dockerfile


Docker can build images automatically by reading the instructions from a Dockerfile. A Dockerfile is a text document that contains all the commands a user could call on the command line to assemble an image. Using docker build users can create an automated build that executes several command-line instructions in succession.

This section guides you on how to use the predefined docker environment to run a sample C program step by step.

### First step:  Wrting the program to run it on a Docker container:
The Cardinal_challege.c file has:
>>>Fibonacci:  the sum of the two preceding numbers: This function works for posetive intergers but if you need to consider negative integers please refer to  https://en.wikipedia.org/wiki/Generalizations_of_Fibonacci_numbers
>>>Reversing a string: It is also helpful to check whether the string is a palindrome or not.
>>>Sorting of an array
>>>Adding, reversing and print function implemetations of a single linked list 

### Step 2: Write a dockerfile
This docker file has a base layer of ubuntu and then installling gcc,compiling the the above C-problems and echoing the output to a schreen.


### You can find the imageconataine from:
https://hub.docker.com/repository/docker/nashnash/lllptrchallenge
pulll using: docker pull nashnash/lllptrchallenge:latest

