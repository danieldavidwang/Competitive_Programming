import java.io.*;

import java.util.*;

 

 

public class Expression {

               static PrintWriter out = new PrintWriter(System.out);

               static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

               static StringTokenizer st;

              

               static int tmpRst = 0;

               static ArrayList<Integer> opd;

               static ArrayList<String> opr;

              

               public static void main(String[] args) throws IOException {

                              try {

                                             tmpRst = 0;

                                             calculate(readLine());

                                             out.println(tmpRst);

                                            

                              } finally {

                                             out.flush();

                                             out.close();

                              }

                             

               }              //end of main()

              

 

              

               static void parseStraight(String ex) {

                              //parse express without bracket

                              opd = new ArrayList<Integer>();

                              opr = new ArrayList<String>();

                              String op1="";

                              char pc = 'A';

                              for(int i=0; i<ex.length(); i++) {

                                             char c = ex.charAt(i);

                                             if(c == ' ') continue;

                                             //System.out.println(">>>>>> pc="+pc+";\t\t c="+c);

                                            

                                             if('0' <= c && c <= '9') op1 += c;

                                             else if(c=='-' && (!('0' <= pc && pc <= '9'))) op1 += c;

                                             else {

                                                            opr.add(""+c);

                                                            opd.add(Integer.parseInt(op1));

                                                            op1 = "";

                                             }

                                             pc = c;

                              }

                              opd.add(Integer.parseInt(op1));

               }

              

               static int calcStraight(String ex) {

                              parseStraight(ex);

                              while (opr.size() > 0) {

//                                          out.println("=== "+opd);

//                                          out.println("=== "+opr);

                                             //iterate operators

                                             if(opr.contains("*") && opr.contains("/")) {

                                                            int idx1 = opr.indexOf("*");

                                                            int idx2 = opr.indexOf("/");

                                                            int tmp = 0;

                                                            if(idx1 < idx2) {

                                                                           tmp = opd.get(idx1) * opd.get(idx1+1);

                                                                           opd.set(idx1, tmp);

                                                                           opd.remove(idx1+1);

                                                                           opr.remove(idx1);

                                                            }

                                                            else {

                                                                           tmp = opd.get(idx2) / opd.get(idx2+1);

                                                                           opd.set(idx2, tmp);

                                                                           opd.remove(idx2+1);

                                                                           opr.remove(idx2);

                                                            }

                                             } else if(opr.contains("*")) {

                                                            int idx1 = opr.indexOf("*");

                                                            int tmp = opd.get(idx1) * opd.get(idx1+1);

                                                            opd.set(idx1, tmp);

                                                            opd.remove(idx1+1);

                                                            opr.remove(idx1);

                                             } else if(opr.contains("/")) {

                                                            int idx1 = opr.indexOf("/");

                                                            int tmp = opd.get(idx1) / opd.get(idx1+1);

                                                            opd.set(idx1, tmp);

                                                            opd.remove(idx1+1);

                                                            opr.remove(idx1);

                                             } else {

                                                            int idx1 = 0;

                                                            String op = opr.get(idx1);

                                                            int tmp = opd.get(idx1) + opd.get(idx1+1);

                                                            if(op.equals("-")) tmp = opd.get(idx1) +- opd.get(idx1+1);

                                                            opd.set(idx1, tmp);

                                                            opd.remove(idx1+1);

                                                            opr.remove(idx1);

                                             }

                              }

                              //System.out.println(">>> tmp = "+opd.get(0));

                              return opd.get(0);

               }

              

              

               static void calculate(String qs) {

                              int idx_rb = qs.indexOf(")");                         //index for the first Right-Bracket ")"

                              //out.println("----- "+qs);

                             

                             

                              if(idx_rb >= 0) {

                                             int idx_lb = (qs.substring(0, idx_rb)).lastIndexOf("("); //index for the last Left-Bracket "(" before ")"

                                            

                                             String ex = qs.substring(idx_lb+1, idx_rb);

                                             ex = ex.trim();

                                            

                                             String rm = (idx_lb>0)?qs.substring(0, idx_lb):"";

                                             if(ex.length()>0) {

                                                            tmpRst = calcStraight(ex);

                                                            rm += tmpRst;

                                             }

                                            

                                             rm += (idx_rb < qs.length()-1)?qs.substring(idx_rb+1):"";

                                             //out.println("+++++ rm="+qs);

                                             calculate(rm);

                                            

                              } else {

                                             tmpRst = calcStraight(qs);

                              }

               }

              

              

              

               static String next () throws IOException {

                              while (st == null || !st.hasMoreTokens())

                                             st = new StringTokenizer(br.readLine().trim());

                              return st.nextToken();

               }

               static long readLong () throws IOException {

                              return Long.parseLong(next());

               }

               static int readInt () throws IOException {

                              return Integer.parseInt(next());

               }

               static double readDouble () throws IOException {

                              return Double.parseDouble(next());

               }

               static String readLine () throws IOException {

                              return br.readLine().trim();

               }

 

}