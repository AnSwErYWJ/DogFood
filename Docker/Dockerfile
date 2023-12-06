FROM ubuntu:20.04 

LABEL maintainer="answerywj" 

ENV TZ="Asia/Shanghai"

RUN set -x \
&& buildDeps='apt-utils' \
&& apt-get update \
&& apt-get install tzdata \
&& ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone \
&& apt-get install -y $buildDeps \
&& apt autoremove \
&& apt-get clean \
&& apt-get autoremove --purge \
&& rm -rf /tmp/* \
&& rm -rf /var/lib/apt/lists/* \
&& rm -rf /var/cache/apt/archives/*

EXPOSE 9696

CMD ["/bin/bash"]