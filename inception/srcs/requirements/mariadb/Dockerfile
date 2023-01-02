FROM debian:buster
EXPOSE 3306

RUN		apt-get -y update &&\
     	apt-get -y upgrade &&\
     	apt-get -y install mariadb-server\
     	vim

COPY	conf/50-server.cnf	/etc/mysql/mariadb.conf.d/
COPY	conf/run.sh		/run.sh
ENTRYPOINT ["bash", "run.sh"]