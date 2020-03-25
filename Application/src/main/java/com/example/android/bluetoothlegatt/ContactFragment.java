package com.example.android.bluetoothlegatt;

import android.os.Bundle;
import android.support.annotation.NonNull;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.RatingBar;
import android.widget.Toast;

import static android.content.ContentValues.TAG;

public class ContactFragment extends Fragment {
    private static final String TAG = "ContactFragment";

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_contact, container, false);
        submitFeedback(view);
        return view;
    }

    public void submitFeedback(View view) {
        final RatingBar ratingBar = view.findViewById(R.id.rating_bar);
        final Button submitButton = view.findViewById(R.id.submit_button);
        submitButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                float appRating = getRating(ratingBar);
            }
        });
    }

    public float getRating(RatingBar ratingBar) {
        return ratingBar.getRating();
    }
}
