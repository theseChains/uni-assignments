import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet(urlPatterns = {"/ServletAppl"})
public class Servlet1 extends HttpServlet {
    static String ast;
    static boolean b;
    static long counter;
    static int cycle;

    /**
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code>
     * methods.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */

    public Servlet1(){
        Servlet1.ast = "a static var c=";
        Servlet1.b = false;
        Servlet1.counter = 0;
        Servlet1.cycle = 0;
    }

    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
            response.setContentType("text/html;charset=UTF-8");
            try (PrintWriter out = response.getWriter()) {
                /* TODO output your page here. You may use following sample code. */
                out.println("<!DOCTYPE html>");
                out.println("<html>");
                out.println("<head>");
                out.println("<title>Здесь должны быть ФИО и № группы</title>");
                out.println("</head>");
                out.println("<body>");
                out.println("<h1>ServletAppl" + request.getServletPath() + "</h1>");

                if (Servlet1.b) Servlet1.b = false;
                else Servlet1.b = true;
                Servlet1.counter++;
                if(Servlet1.cycle < 5){
                    Servlet1.cycle ++;
                }else{
                    Servlet1.cycle = 1;
                }

                out.println("<h3> Servlet1.ast + Servlet1.b :" + Servlet1.ast + Servlet1.b + "</h3>");
                out.println("<h3> Servlet1.counter : " + Servlet1.counter + "</h3>");
                out.println("<h3> Servlet1.cycle :" + Servlet1.cycle + "</h3>");

                String[][] tbl = new String[3][3];
                for(int i=0; i<3; i++){
                    for(int j=0; j<3; j++){
                        tbl[i][j] = Integer.toString(i+1) + "&" + Integer.toString(j+1);
                    }
                }

                String prm1 = request.getParameter("prm1");
                String prm2 = request.getParameter("prm2");
                String prm3 = request.getParameter("prm3");


                out.println("<h" + Servlet1.cycle + "><table border>"+
                        "<tr>" + "<td>" + tbl[0][0] + "</td>" + "<td>prm1=" + prm1 + "</td>" + "<td>1.3</td>" +
                        "<tr>" + "<td>prm2=" + prm2 + "</td>" + "<td>pr2</td>" + "<td>2.3</td>" +
                        "<tr>" + "<td>prm3=" + prm3 + "</td>" + "<td>3.2</td>" + "<td>" + tbl[2][2] + "</td>" +
                        "</tr>"
                        + "</table></h" + Servlet1.cycle + ">");

                //=============II
                out.println("</body>");
                out.println("</html>");
            }
    }
    // <editor-fold defaultstate="collapsed" desc="HttpServlet methods. Click on the + sign on the left to edit the code.">
    /**
     * Handles the HTTP <code>GET</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
        throws ServletException, IOException {
        processRequest(request, response);
    }
    /**
     * Handles the HTTP <code>POST</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
        throws ServletException, IOException {
        processRequest(request, response);
    }
    /**
     * Returns a short description of the servlet.
     *
     * @return a String containing servlet description
     */
    @Override
    public String getServletInfo() {
        return "Short description";
    }// </editor-fold>
}
