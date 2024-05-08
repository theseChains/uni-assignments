<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page import="java.util.ArrayList"%>
<jsp:useBean id="mybean" scope="session" class="jspappl.TaskHandler" />
<%
    String inputNumbersString = request.getParameter("inputNumbers");
    String[] numbersArrayString = inputNumbersString.split(" ");

    int[] numbersArray = new int[numbersArrayString.length];
    for (int i = 0; i < numbersArrayString.length; ++i) {
        numbersArray[i] = Integer.parseInt(numbersArrayString[i]);
    }

    mybean.calculateNewResult(numbersArray);
    ArrayList<String> results = mybean.getResults();
    request.setAttribute("results", results);
    ArrayList<int[]> arrays = mybean.getArrays();
    request.setAttribute("arrays", arrays);
    pageContext.forward("finish-page.jsp");
%>
