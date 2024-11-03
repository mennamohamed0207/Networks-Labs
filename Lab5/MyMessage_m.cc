//
// Generated file, do not edit! Created by opp_msgtool 6.0 from MyMessage.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include <memory>
#include <type_traits>
#include "MyMessage_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

MyMessage_Base::MyMessage_Base(const char *name, short kind) : ::omnetpp::cPacket(name, kind)
{
}

MyMessage_Base::MyMessage_Base(const MyMessage_Base& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

MyMessage_Base::~MyMessage_Base()
{
    delete [] this->M_Payload;
}

MyMessage_Base& MyMessage_Base::operator=(const MyMessage_Base& other)
{
    if (this == &other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void MyMessage_Base::copy(const MyMessage_Base& other)
{
    this->M_Type = other.M_Type;
    this->M_Header = other.M_Header;
    delete [] this->M_Payload;
    this->M_Payload = (other.M_Payload_arraysize==0) ? nullptr : new char[other.M_Payload_arraysize];
    M_Payload_arraysize = other.M_Payload_arraysize;
    for (size_t i = 0; i < M_Payload_arraysize; i++) {
        this->M_Payload[i] = other.M_Payload[i];
    }
    this->M_Trailer = other.M_Trailer;
}

void MyMessage_Base::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->M_Type);
    doParsimPacking(b,this->M_Header);
    b->pack(M_Payload_arraysize);
    doParsimArrayPacking(b,this->M_Payload,M_Payload_arraysize);
    doParsimPacking(b,this->M_Trailer);
    // field anotherField is abstract or custom -- please do packing in customized class
}

void MyMessage_Base::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->M_Type);
    doParsimUnpacking(b,this->M_Header);
    delete [] this->M_Payload;
    b->unpack(M_Payload_arraysize);
    if (M_Payload_arraysize == 0) {
        this->M_Payload = nullptr;
    } else {
        this->M_Payload = new char[M_Payload_arraysize];
        doParsimArrayUnpacking(b,this->M_Payload,M_Payload_arraysize);
    }
    doParsimUnpacking(b,this->M_Trailer);
    // field anotherField is abstract or custom -- please do unpacking in customized class
}

int MyMessage_Base::getM_Type() const
{
    return this->M_Type;
}

void MyMessage_Base::setM_Type(int M_Type)
{
    this->M_Type = M_Type;
}

char MyMessage_Base::getM_Header() const
{
    return this->M_Header;
}

void MyMessage_Base::setM_Header(char M_Header)
{
    this->M_Header = M_Header;
}

size_t MyMessage_Base::getM_PayloadArraySize() const
{
    return M_Payload_arraysize;
}

char MyMessage_Base::getM_Payload(size_t k) const
{
    if (k >= M_Payload_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)M_Payload_arraysize, (unsigned long)k);
    return this->M_Payload[k];
}

void MyMessage_Base::setM_PayloadArraySize(size_t newSize)
{
    char *M_Payload2 = (newSize==0) ? nullptr : new char[newSize];
    size_t minSize = M_Payload_arraysize < newSize ? M_Payload_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        M_Payload2[i] = this->M_Payload[i];
    for (size_t i = minSize; i < newSize; i++)
        M_Payload2[i] = 0;
    delete [] this->M_Payload;
    this->M_Payload = M_Payload2;
    M_Payload_arraysize = newSize;
}

void MyMessage_Base::setM_Payload(size_t k, char M_Payload)
{
    if (k >= M_Payload_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)M_Payload_arraysize, (unsigned long)k);
    this->M_Payload[k] = M_Payload;
}

void MyMessage_Base::insertM_Payload(size_t k, char M_Payload)
{
    if (k > M_Payload_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)M_Payload_arraysize, (unsigned long)k);
    size_t newSize = M_Payload_arraysize + 1;
    char *M_Payload2 = new char[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        M_Payload2[i] = this->M_Payload[i];
    M_Payload2[k] = M_Payload;
    for (i = k + 1; i < newSize; i++)
        M_Payload2[i] = this->M_Payload[i-1];
    delete [] this->M_Payload;
    this->M_Payload = M_Payload2;
    M_Payload_arraysize = newSize;
}

void MyMessage_Base::appendM_Payload(char M_Payload)
{
    insertM_Payload(M_Payload_arraysize, M_Payload);
}

void MyMessage_Base::eraseM_Payload(size_t k)
{
    if (k >= M_Payload_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)M_Payload_arraysize, (unsigned long)k);
    size_t newSize = M_Payload_arraysize - 1;
    char *M_Payload2 = (newSize == 0) ? nullptr : new char[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        M_Payload2[i] = this->M_Payload[i];
    for (i = k; i < newSize; i++)
        M_Payload2[i] = this->M_Payload[i+1];
    delete [] this->M_Payload;
    this->M_Payload = M_Payload2;
    M_Payload_arraysize = newSize;
}

char MyMessage_Base::getM_Trailer() const
{
    return this->M_Trailer;
}

void MyMessage_Base::setM_Trailer(char M_Trailer)
{
    this->M_Trailer = M_Trailer;
}

class MyMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_M_Type,
        FIELD_M_Header,
        FIELD_M_Payload,
        FIELD_M_Trailer,
        FIELD_anotherField,
    };
  public:
    MyMessageDescriptor();
    virtual ~MyMessageDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(MyMessageDescriptor)

MyMessageDescriptor::MyMessageDescriptor() : omnetpp::cClassDescriptor("MyMessage", "omnetpp::cPacket")
{
    propertyNames = nullptr;
}

MyMessageDescriptor::~MyMessageDescriptor()
{
    delete[] propertyNames;
}

bool MyMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MyMessage_Base *>(obj)!=nullptr;
}

const char **MyMessageDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = { "customize",  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *MyMessageDescriptor::getProperty(const char *propertyName) const
{
    if (!strcmp(propertyName, "customize")) return "true";
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int MyMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 5+base->getFieldCount() : 5;
}

unsigned int MyMessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_M_Type
        FD_ISEDITABLE,    // FIELD_M_Header
        FD_ISARRAY | FD_ISEDITABLE | FD_ISRESIZABLE,    // FIELD_M_Payload
        FD_ISEDITABLE,    // FIELD_M_Trailer
        FD_ISEDITABLE,    // FIELD_anotherField
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *MyMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "M_Type",
        "M_Header",
        "M_Payload",
        "M_Trailer",
        "anotherField",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int MyMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "M_Type") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "M_Header") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "M_Payload") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "M_Trailer") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "anotherField") == 0) return baseIndex + 4;
    return base ? base->findField(fieldName) : -1;
}

const char *MyMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_M_Type
        "char",    // FIELD_M_Header
        "char",    // FIELD_M_Payload
        "char",    // FIELD_M_Trailer
        "int",    // FIELD_anotherField
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **MyMessageDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *MyMessageDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int MyMessageDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    MyMessage_Base *pp = omnetpp::fromAnyPtr<MyMessage_Base>(object); (void)pp;
    switch (field) {
        case FIELD_M_Payload: return pp->getM_PayloadArraySize();
        default: return 0;
    }
}

void MyMessageDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    MyMessage_Base *pp = omnetpp::fromAnyPtr<MyMessage_Base>(object); (void)pp;
    switch (field) {
        case FIELD_M_Payload: pp->setM_PayloadArraySize(size); break;
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'MyMessage_Base'", field);
    }
}

const char *MyMessageDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    MyMessage_Base *pp = omnetpp::fromAnyPtr<MyMessage_Base>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MyMessageDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    MyMessage_Base *pp = omnetpp::fromAnyPtr<MyMessage_Base>(object); (void)pp;
    switch (field) {
        case FIELD_M_Type: return long2string(pp->getM_Type());
        case FIELD_M_Header: return long2string(pp->getM_Header());
        case FIELD_M_Payload: return long2string(pp->getM_Payload(i));
        case FIELD_M_Trailer: return long2string(pp->getM_Trailer());
        case FIELD_anotherField: return long2string(pp->getAnotherField());
        default: return "";
    }
}

void MyMessageDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MyMessage_Base *pp = omnetpp::fromAnyPtr<MyMessage_Base>(object); (void)pp;
    switch (field) {
        case FIELD_M_Type: pp->setM_Type(string2long(value)); break;
        case FIELD_M_Header: pp->setM_Header(string2long(value)); break;
        case FIELD_M_Payload: pp->setM_Payload(i,string2long(value)); break;
        case FIELD_M_Trailer: pp->setM_Trailer(string2long(value)); break;
        case FIELD_anotherField: pp->setAnotherField(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MyMessage_Base'", field);
    }
}

omnetpp::cValue MyMessageDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    MyMessage_Base *pp = omnetpp::fromAnyPtr<MyMessage_Base>(object); (void)pp;
    switch (field) {
        case FIELD_M_Type: return pp->getM_Type();
        case FIELD_M_Header: return pp->getM_Header();
        case FIELD_M_Payload: return pp->getM_Payload(i);
        case FIELD_M_Trailer: return pp->getM_Trailer();
        case FIELD_anotherField: return pp->getAnotherField();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'MyMessage_Base' as cValue -- field index out of range?", field);
    }
}

void MyMessageDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MyMessage_Base *pp = omnetpp::fromAnyPtr<MyMessage_Base>(object); (void)pp;
    switch (field) {
        case FIELD_M_Type: pp->setM_Type(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_M_Header: pp->setM_Header(omnetpp::checked_int_cast<char>(value.intValue())); break;
        case FIELD_M_Payload: pp->setM_Payload(i,omnetpp::checked_int_cast<char>(value.intValue())); break;
        case FIELD_M_Trailer: pp->setM_Trailer(omnetpp::checked_int_cast<char>(value.intValue())); break;
        case FIELD_anotherField: pp->setAnotherField(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MyMessage_Base'", field);
    }
}

const char *MyMessageDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr MyMessageDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    MyMessage_Base *pp = omnetpp::fromAnyPtr<MyMessage_Base>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void MyMessageDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    MyMessage_Base *pp = omnetpp::fromAnyPtr<MyMessage_Base>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MyMessage_Base'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

