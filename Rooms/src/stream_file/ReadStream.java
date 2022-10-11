package stream_file;
import java.io.*;
import java.util.Scanner;
import java.util.stream.Stream;

public class ReadStream extends Thread {

    private String fileName;
    private String json;
    /**
     * @param fn - имя файла для чтения
     */
    public ReadStream(String fn){
        super("write stream");
        this.fileName = fn;
    }

    public void run(){
        try {
            FileReader reader = new FileReader(this.fileName);
            Scanner scan = new Scanner(reader);
            this.json = scan.nextLine();
            System.out.println(this.fileName +" was read");
            reader.close();
            scan.close();
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }

    /**
     * @return json - результат чтения в формате String
     */
    public String getJson(){
        return this.json;
    }
}
