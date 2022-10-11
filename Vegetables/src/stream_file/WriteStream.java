package stream_file;


import java.io.FileWriter;
import java.io.IOException;

public class WriteStream extends Thread{

    private String fileName;
    private String json;
    /**
     * @param fn - имя файла для чтения
     */
    public WriteStream(String fn, String j){
        super("write stream");
        this.fileName = fn;
        this.json = j;
    }

    public void run(){

        try {
            FileWriter writer = new FileWriter(this.fileName, false);
            writer.write(this.json);
            writer.close();
            System.out.println(this.fileName + " has written");

        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }
}
