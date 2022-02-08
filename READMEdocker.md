1. **docker-compose entry**

  Runs a container which you can run a docker exec command

  ```
  version: "3.9"
  services:
    audiohealth:
      container_name: audiohealth
      image: prometheus199/dockeraudiohealth:latest
      restart: unless-stopped
      volumes:
        - ~/samples:/app/samples

2. **To process wav file**

  Refer to <https://github.com/hiveeyes/audiohealth> documentation for options

  ```
  docker exec audiohealth python audiohealth.py analyze --audiofile ./samples/hive12022-02-07T1405.wav --analyzer tools/osbh-audioanalyzer/bin/test

  ```
