cmake_minimum_required(VERSION 3.10)

aux_source_directory(. ALL_SOURCE)

link_eigen("${ALL_SOURCE}")