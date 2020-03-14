package com.example.android.bluetoothlegatt;

import android.content.Intent;
import android.graphics.Color;
import android.graphics.ColorMatrixColorFilter;
import android.graphics.drawable.Drawable;
import android.os.Bundle;
import android.support.annotation.NonNull;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

import org.w3c.dom.Text;

public class HomeFragment extends Fragment {
    private static final float[] NEGATIVE = {
            -1.0f, 0, 0, 0, 255, // red
            0, -1.0f, 0, 0, 255, // green
            0, 0, -1.0f, 0, 255, // blue
            0, 0, 0, 1.0f, 0  // alpha
    };

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_home, container, false);
        TextView about_card = view.findViewById(R.id.about_card);
        TextView help_card = view.findViewById(R.id.help_card);
        TextView contact_card = view.findViewById(R.id.contact_card);
        setNegative(about_card);
        setNegative(help_card);
        setNegative(contact_card);
        moveToDeviceScan(view);
        return view;
    }

    public void moveToDeviceScan(View view) {
        Button button = view.findViewById(R.id.moveToDeviceScan);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent(getActivity(), DeviceScanActivity.class);
                startActivity(intent);
            }
        });
    }

    public void setNegative(TextView textView) {
        for (Drawable drawable: textView.getCompoundDrawables()) {
            if (drawable != null) {
                drawable.setColorFilter(new ColorMatrixColorFilter(NEGATIVE));
            }
        }
    }
}
