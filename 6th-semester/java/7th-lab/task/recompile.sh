javac -cp javax.servlet-api-3.1.0.jar MyServlet.java
rm WEB-INF/classes/*.class
mv MyServlet.class WEB-INF/classes
cp -r ../task /home/sublunary/Downloads/apache-tomcat-9.0.88/webapps
