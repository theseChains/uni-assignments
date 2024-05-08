<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page import="java.util.ArrayList"%>
<jsp:useBean id="mybean" scope="session" class="jspappl.TaskHandler" />
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>Финишная страница</title>
</head>
<body>
    <h3>Результаты работы:</h3>

    <table id="resultsTable" border="1">
        <tr>
            <th>Данные</th>
            <th>Результат</th>
        </tr>
        <% ArrayList<String> results = (ArrayList<String>) request.getAttribute("results"); %>
        <% ArrayList<int[]> arrays = (ArrayList<int[]>) request.getAttribute("arrays"); %>
        <% if (arrays != null && results != null) {
        for (int i = 0; i < arrays.size(); i++) { %>
        <tr>
            <td>
                [<%
                int[] array = arrays.get(i);
                for (int j = 0; j < array.length; ++j) {
                    out.print(array[j]);
                    out.print(" ");
                }
                %>]
            </td>
            <td><%= results.get(i) %></td>
        </tr>
        <%     }
        } %>
    </table>

    <a href="main-page.jsp">На главную страницу</a>
</body>
</html>
