#!/bin/bash
(find . && ls -d -print) | grep -c /
