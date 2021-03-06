/*
* Copyright (c) 2002-2006 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of the License "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:   Declaration of the WlanWsaConfigure class.
*
*/

/*
* %version: 9 %
*/

#ifndef WLANWSACONFIGURE_H
#define WLANWSACONFIGURE_H

#include "UmacWsaCommand.h"

/**
*  Encapsulates the execution of Configure WHA command.
*
*  @lib wlanumac.lib
*  @since S60 v3.1
*/
class WlanWsaConfigure : public WlanWsaCommand
    {

public:

    /**
    * C++ default constructor.
    */
    WlanWsaConfigure() : 
         iData( NULL ), iLength( 0 ) {};

public:

    void Set( 
        WlanContextImpl& aCtxImpl, 
        const TAny* aData, 
        TUint32 aLength );

private:

    virtual void Entry( WlanContextImpl& aCtxImpl );
#ifndef NDEBUG 
    virtual const TInt8* GetStateName( TUint8& aLength ) const;
#endif // !NDEBUG 

    virtual void CommandResponse( 
        WlanContextImpl& aCtxImpl, 
        WHA::TCommandId aCommandId, 
        WHA::TStatus aStatus,
        const WHA::UCommandResponseParams& aCommandResponseParams );

    // Prohibit copy constructor.
    WlanWsaConfigure( const WlanWsaConfigure& );
    // Prohibit assigment operator.
    WlanWsaConfigure& operator= ( const WlanWsaConfigure& );

private:    // Data

#ifndef NDEBUG 
    static const TInt8  iName[];
#endif

    const TAny*         iData;
    TUint32             iLength;
    };

#endif      // WLANWSACONFIGURE_H
