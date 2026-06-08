FROM ubuntu:22.04

# Install dependencies
RUN apt-get update && apt-get install -y \
    g++ \
    make \
    && rm -rf /var/lib/apt/lists/*

# Set working directory
WORKDIR /app

# Copy backend files (external dependencies are already included in the repo)
COPY . /app/

# Build the API server (build only, don't run)
RUN make -f makefile directories && make -f makefile build/api_server

# Expose port 8080
EXPOSE 8080

# Run the API server
CMD ["./build/api_server"]
