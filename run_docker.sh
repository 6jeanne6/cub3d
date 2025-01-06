#!/bin/bash

# Configurer DISPLAY pour macOS avec XQuartz
export DISPLAY=host.docker.internal:0

# Autoriser les connexions X11 pour localhost
xhost + 127.0.0.1

# Lancer le conteneur Docker avec X11 forwarding
docker run -it --rm \
    -e DISPLAY=$DISPLAY \
    -v /tmp/.X11-unix:/tmp/.X11-unix \
    -v $(pwd):/app \
    votre_image /bin/bash

# Nettoyer les autorisations X11
xhost - 127.0.0.1


# export DISPLAY=host.docker.internal:0