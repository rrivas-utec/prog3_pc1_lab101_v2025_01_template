#!/usr/bin/env bash

project_name='prog3_pc1_lab101_v2025_01'
source_code='
  geodesy.h geodesy.cpp
  '
rm -f ${project_name}.zip
zip -r -S ${project_name} ${source_code}