#!/bin/bash

# For each header file in /usr/include (breadth first?)
# Sanitize filename
# Check to see if we've already processed this one
# Find out what debian package it belongs to
# Find out what library binary the header corresponds to
# Create library folder if necessary
# Load or create library meta descriptor 
# Process header with libtooling to generate header description binary
# Write lib meta containing meta and new description binary filename
# Next
