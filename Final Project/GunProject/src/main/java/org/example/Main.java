package org.example;
import edu.cmu.sphinx.api.*;

import java.io.IOException;

class SpeechRecognitionExample {
    public static void main(String[] args) {
        try {
            // Create a configuration for speech recognition
            Configuration configuration = new Configuration();

            // Set the acoustic model
            configuration.setAcousticModelPath("resource:/edu/cmu/sphinx/models/en-us/en-us");

            // Set the dictionary
            configuration.setDictionaryPath("resource:/edu/cmu/sphinx/models/en-us/cmudict-en-us.dict");

            // Set the language model
            configuration.setLanguageModelPath("resource:/edu/cmu/sphinx/models/en-us/en-us.lm.bin");

            // Create a speech recognizer
            LiveSpeechRecognizer recognizer = new LiveSpeechRecognizer(configuration);

            // Start recognition
            recognizer.startRecognition(true);
            System.out.println("Listening...");

            SpeechResult result;
            while ((result = recognizer.getResult()) != null) {
                System.out.println("Recognized: " + result.getHypothesis());
            }

            recognizer.stopRecognition();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}