#!/bin/bash

cd package

twine upload --repository pypi dist/*

cd ..
