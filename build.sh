mkdir tools/osbh-audioanalyzer/bin scriptname >/dev/null 2>&1

GPP=g++

# Check for modern compiler
GPP_49=g++-mp-4.9
if [ ! -z $(which $GPP_49) ]; then
    GPP=$(which $GPP_49)
fi

$GPP -std=c++11 tools/osbh-audioanalyzer/main.cpp tools/osbh-audioanalyzer/createFilters.cpp tools/osbh-audioanalyzer/featureExtractor.cpp tools/osbh-audioanalyzer/filter.cpp tools/osbh-audioanalyzer/classifier.cpp -o tools/osbh-audioanalyzer/bin/test
