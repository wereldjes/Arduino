package com.example.opdracht91;

import androidx.appcompat.app.AppCompatActivity;

import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;
import android.os.Bundle;
import android.widget.Button;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.nio.charset.StandardCharsets;
import java.util.UUID;

public class MainActivity extends AppCompatActivity {
    private final String uuid = "00001101-0000-1000-8000-00805F9B34FB";
    private OutputStream outStream;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        final Button con = findViewById(R.id.con);
        final Button off = findViewById(R.id.off);

        con.setOnClickListener(e -> on());
        off.setOnClickListener(e -> off());
    }

    public void on() {
        connectThread("1");

    }

    public void off() {
        connectThread("0");

    }

    public void connectThread(String mark) {
        BluetoothAdapter adapter = BluetoothAdapter.getDefaultAdapter();
        BluetoothDevice hc05 = adapter.getRemoteDevice("98:D3:51:FD:AE:B5");
        BluetoothSocket tmp = null;


        try {
            tmp = hc05.createRfcommSocketToServiceRecord(UUID.fromString(uuid));
        } catch (IOException e) {
            e.printStackTrace();
        }

        try {
            tmp.connect();

            outStream = tmp.getOutputStream();
            outStream.write(mark.getBytes(StandardCharsets.UTF_8));
            outStream.flush();

        } catch (IOException e) {
            e.printStackTrace();
            try {
                tmp.close();
            } catch (IOException ioException) {
                ioException.printStackTrace();
            }
        }

        try {
            tmp.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }
}