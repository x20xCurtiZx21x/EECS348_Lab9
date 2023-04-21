# Set the base image to use
FROM gcc:latest
# Copy the C program into the container
COPY program1.c .
# Compile the C program
RUN gcc -o program1 program1.c
# Set the command to run when the container starts
CMD ["./program1"]