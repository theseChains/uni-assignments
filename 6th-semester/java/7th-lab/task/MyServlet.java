import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.util.Arrays;
import java.util.ArrayList;

@WebServlet(urlPatterns = {"/ServletAppl"})
public class MyServlet extends HttpServlet {
    static long numberOfPageReloads;
    static int fontSize = 16;
    static ArrayList<int[]> arrays = new ArrayList<>();

    public MyServlet() {
        MyServlet.numberOfPageReloads = 0;
    }

    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        try (PrintWriter out = response.getWriter()) {
            String fontSizeParam = request.getParameter("fontSize");
            if (fontSizeParam != null && !fontSizeParam.isEmpty()) {
                try {
                    fontSize = Integer.parseInt(fontSizeParam);
                } catch (NumberFormatException e) {
                    out.println("<p>Error: Font size parameter is not a valid integer.</p>");
                    return;
                }
            }

            String fullName = request.getParameter("fullName");
            String groupNumber = request.getParameter("groupNumber");

            String argsParam = request.getParameter("args");
            arrays.add(parseArgs(argsParam));

            out.println("<!DOCTYPE html>");
            out.println("<html>");
            out.println("<head>");
            out.println("<title>stuff</title>");
            out.println("</head>");
            out.println("<body>");
            out.println("<h1>ServletAppl" + request.getServletPath() + "</h1>");

            out.println("<h3>Ф.И.О студента: " + fullName + "</h3>");
            out.println("<h3>Номер группы: " + groupNumber + "</h3>");

            ++MyServlet.numberOfPageReloads;
            out.println("<h3>Количество обращений к странице: " + MyServlet.numberOfPageReloads + "</h3>");

            out.println("<h3>Результаты выполнения основной функции:</h3>");
            out.println("<table>");
            for (int[] array : arrays) {
                if (array.length == 0)
                    continue;

                String arrayAsString = Arrays.toString(array);
                String result = getResult(array);
                String combinedString = arrayAsString.substring(1, arrayAsString.length() - 1) + " => " + result;

                out.println("<tr><td style='font-size: " + fontSize + "px;'>" + combinedString + "</td></tr>");
            }
            out.println("</table>");

            if (fontSize > 10) {
                fontSize -= 2;
            } else {
                out.println("<p>Дальнейшее уменьшение размера текста в таблице не возможно</p>");
            }

            out.println("</body>");
            out.println("</html>");
        }
    }

    private int[] parseArgs(String argsParam) {
        if (argsParam != null && !argsParam.isEmpty()) {
            String[] argsArray = argsParam.split(" ");
            int[] numbers = new int[argsArray.length];
            for (int i = 0; i < argsArray.length; i++) {
                numbers[i] = Integer.parseInt(argsArray[i]);
            }
            return numbers;
        }
        return new int[0];
    }

    private String getResult(int[] inputNumbers) {
        int evenPositiveCount = 0;
        int oddPositiveCount = 0;

        for (int num : inputNumbers) {
            if (num > 0) {
                if (num % 2 == 0) {
                    evenPositiveCount++;
                } else {
                    oddPositiveCount++;
                }
            }
        }

        if (evenPositiveCount > oddPositiveCount) {
            return "Чётных и положительных чисел больше";
        } else if (evenPositiveCount < oddPositiveCount) {
            return "Нечётных и положительных чисел больше";
        } else {
            return "Чётных и нечётных положительных чисел поровну";
        }
    }

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
        throws ServletException, IOException {
        processRequest(request, response);
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
        throws ServletException, IOException {
        processRequest(request, response);
    }

    @Override
    public String getServletInfo() {
        return "lab";
    }
}
