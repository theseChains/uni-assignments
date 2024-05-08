<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
        <%! int counter; %>
        <jsp:useBean id="mybean" scope="session" class="jspappl.NameHandler" />
        <%mybean.addCounter(Integer.parseInt(request.getParameter("name")));%>
        <jsp:setProperty name="mybean" property="name" />
        <h3>Приветствую тебя, <jsp:getProperty name="mybean" property="name" />, так.</h3>
        <h3>Приветствую тебя, ${mybean.name}, и вот так. </h3>
        <form name="Back form" action="jsp_1.jsp">
            <input type="submit" value="Back" name="button2" />
        </form>
        <h3>Счётчик <jsp:getProperty name="mybean" property="counter" /></h3>
        <h3>Счётчик <%=++counter %></h3>
    </body>
</html>
