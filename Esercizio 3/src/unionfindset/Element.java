public class Element<T> {
    T data;
    Element parent;

    public Element(T data) {
        this.data = data;
        this.parent = this;
    }

    public Element getParent() {
        return this.parent;
    }

    public void setParent(Element parent) {
        this.parent = parent;
    }

    public void setData(T data) {
        this.data = data;
    }

    public T getdata() {
        return this.data;
    }

}
