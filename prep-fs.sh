#!/usr/bin/env bash

BINARY=$1
FSDIR=$2

function required {
  BINARY=${1}
  DIRPATH=$(dirname ${1})

  ELF=$(readelf -a ${BINARY})

  INTERP=$(echo "${ELF}" | grep "Requesting program interpreter")

  INTERP_PATH=$(echo "${INTERP}" | sed -E "s/.*interpreter: (.*?)\]/\1/")

  if [ -n "${INTERP_PATH}" ] ; then
    echo "${INTERP_PATH}"
    DIRPATH=$(dirname ${INTERP_PATH})
  fi

  echo "${ELF}" | grep "Shared library:" | \
      sed -E "s/.*Shared library: \[(.*?)\]/\1/" | \
      while read line ; do
    if [ -n "${line}" ] ; then  
      echo "${DIRPATH}/${line}"
      required "${DIRPATH}/${line}"
    fi
  done
}

required "${BINARY}"
