class response {
    private:
        int correct;
        int incorrect;

    public:
        // Constructor
        response(int corr = 0, int incorr = 0);

        // Getters
        int getCorrect();
        int getIncorrect();

        // Setters
        void setCorrect(int c);
        void setIncorrect(int i);
};