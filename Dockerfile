# For more information, please refer to https://aka.ms/vscode-docker-python
FROM python:3.8-slim

# Keeps Python from generating .pyc files in the container
ENV PYTHONDONTWRITEBYTECODE=1

# Turns off buffering for easier container logging
ENV PYTHONUNBUFFERED=1

# Install requirements

RUN apt-get -y update
RUN apt-get -y install make python3-aubio aubio-tools build-essential sox libsox-fmt-all xvfb xauth youtube-dl
COPY requirements.txt .
RUN python -m pip install -r requirements.txt
RUN python -m pip install aubio

WORKDIR /app
COPY . /app

#Make osbh audio
RUN chmod +x build.sh
RUN ./build.sh

#to run analysere use: python audiohealth.py...................

# Creates a non-root user with an explicit UID and adds permission to access the /app folder
# For more info, please refer to https://aka.ms/vscode-docker-python-configure-containers
RUN adduser -u 5678 --disabled-password --gecos "" appuser && chown -R appuser /app
USER appuser

# During debugging, this entry point will be overridden. For more information, please refer to https://aka.ms/vscode-docker-python-debug
#CMD ["python", "audiohealth.py"]
CMD tail -f /dev/null