<%@page contentType="text/html"%>
<%@page pageEncoding="UTF-8"%>
<%@taglib prefix="f" uri="http://java.sun.com/jsf/core"%>
<%@taglib prefix="h" uri="http://java.sun.com/jsf/html"%>
<!DOCTYPE html>
<html xmlns:h="http://xmlns.jcp.org/jsf/html" xmlns:f="http://xmlns.jcp.org/jsf/core">
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Словарь-переводчик</title>
    </head>
    <body>
        <jsp:useBean id="mybean" scope="session" class="jspappl.NameHandler" />
        <h3>Введите ваше имя</h3>
        <form name="Input form" action="jsp2.jsp">
            <input type="text" name="name" />
            <input type="submit" value="OK" name="button1" />
            <%mybean.addCounter(1);%>
        </form>
        <a href="jsp_2.jsp?name=123">Переход</a>
    </body>
</html>
