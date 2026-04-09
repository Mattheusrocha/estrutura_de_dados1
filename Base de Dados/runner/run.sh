#!/usr/bin/env bash

set -e

filesC=( ../src/*.c )

if [ ! -e "${filesC[0]}" ]; then
    echo "Nenhum arquivo .c encontrado em src."
    exit 1
fi

echo "Arquivos C encontrados:"
printf '%s\n' "${filesC[@]}"

mkdir -p output

echo "Compilando..."

gcc "${filesC[@]}" "$@" -o ../output/main

echo "Executando..."

if [[ "$OS" == "Windows_NT" ]]; then
    ./output/main.exe
else
    ./output/main
fi