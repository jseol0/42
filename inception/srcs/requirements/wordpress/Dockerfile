FROM	debian:buster

RUN		apt-get update -y &&\
		apt-get upgrade -y
RUN		apt-get -y install php7.3\
		php-fpm\
		php-mysql\
		mariadb-client\
		wget\
		curl

# wordpress 
RUN		wget https://wordpress.org/wordpress-5.9.2.tar.gz -P /var/www
RUN		cd /var/www &&\
		tar -xvf wordpress-5.9.2.tar.gz &&\
		rm wordpress-5.9.2.tar.gz

#  config file 
COPY	./conf/www.conf			/etc/php/7.3/fpm/pool.d

# wordpress /var/www/wordpress 
RUN		chown -R root:root /var/www/wordpress

# wordpress-client 
RUN		curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar &&\
		chmod +x wp-cli.phar &&\
		mv wp-cli.phar /usr/local/bin/wp

# run.sh wordpress 
COPY	./tools/run.sh /
ENTRYPOINT ["bash", "run.sh"]