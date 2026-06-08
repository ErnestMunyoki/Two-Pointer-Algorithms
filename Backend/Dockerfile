FROM ubuntu:22.04

# Install dependencies
RUN apt-get update && apt-get install -y \
    g++ \
    make \
    wget \
    && rm -rf /var/lib/apt/lists/*

# Set working directory
WORKDIR /app

# Copy backend files
COPY . /app/

# Download external dependencies
RUN mkdir -p external && \
    cd external && \
    wget -q https://github.com/yhirose/cpp-httplib/archive/refs/tags/v0.15.3.tar.gz && \
    tar -xzf v0.15.3.tar.gz && \
    mv cpp-httplib-0.15.3 cpp-httplib && \
    wget -q https://github.com/nlohmann/json/archive/refs/tags/v3.11.3.tar.gz && \
    tar -xzf v3.11.3.tar.gz && \
    mv json-3.11.3 json && \
    rm -f cpp-httplib.tar.gz json.tar.gz

# Build the API server
RUN make -f makefile api

# Expose port 8080
EXPOSE 8080

# Run the API server
CMD ["./build/api_server"]
