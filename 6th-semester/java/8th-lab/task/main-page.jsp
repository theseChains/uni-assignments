<%@page contentType="text/html"%>
<%@page pageEncoding="UTF-8"%>
<%@taglib prefix="f" uri="http://java.sun.com/jsf/core"%>
<%@taglib prefix="h" uri="http://java.sun.com/jsf/html"%>
<!DOCTYPE html>
<html xmlns:h="http://xmlns.jcp.org/jsf/html" xmlns:f="http://xmlns.jcp.org/jsf/core">
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Главная страница</title>
    </head>
    <body>
        <jsp:useBean id="mybean" scope="session" class="jspappl.TaskHandler" />
        <h3>Введите числа (через пробел)</h3>
        <form action="process-input.jsp" method="post">
            <input type="text" name="inputNumbers" placeholder="Enter numbers">
            <input type="submit" value="Compute">
        </form>
        <% mybean.incrementCounter(); %>
        <h3>Значение счётчика: <%= mybean.getCounter() %></h3>
    </body>
</html>
