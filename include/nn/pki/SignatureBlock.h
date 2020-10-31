#pragma once
#include <tc/ByteData.h>
#include <tc/ArgumentNullException.h>
#include <tc/ArgumentOutOfRangeException.h>
#include <nn/pki/sign.h>

namespace nn
{
namespace pki
{
	class SignatureBlock
	{
	public:
		SignatureBlock();
		SignatureBlock(const SignatureBlock& other);

		void operator=(const SignatureBlock& other);
		bool operator==(const SignatureBlock& other) const;
		bool operator!=(const SignatureBlock& other) const;

		// IByteModel
		void toBytes();
		void fromBytes(const byte_t* src, size_t size);
		const tc::ByteData& getBytes() const;

		// variables
		void clear();

		pki::sign::SignatureId getSignType() const;
		void setSignType(pki::sign::SignatureId type);

		bool isLittleEndian() const;
		void setLittleEndian(bool isLE);

		const tc::ByteData& getSignature() const;
		void setSignature(const tc::ByteData& signature);
	
		
	private:
		const std::string kModuleName = "SIGNATURE_BLOCK";

		// raw binary
		tc::ByteData mRawBinary;

		// variables
		pki::sign::SignatureId mSignType;
		bool mIsLittleEndian;
		tc::ByteData mSignature;
	};
}
}