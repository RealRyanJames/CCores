template <typename TypePoint>
class Option
{

public:
    Option(TypePoint t)
    {

        this->isOwned = t;
    }

    bool onEnabled()
    {

        if (this->isOwned)
        {
            return true;
        }

        return false;
    }

private:
    TypePoint isOwned;
};