/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#include "config.h"

#if ENABLE(WORKERS)

#include "JSWorker.h"

#include "EventListener.h"
#include "JSEventListener.h"
#include "Worker.h"
#include <runtime/Error.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSWorker);

/* Hash table */

static const HashTableValue JSWorkerTableValues[2] =
{
    { "onmessage", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsWorkerOnmessage), (intptr_t)setJSWorkerOnmessage },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSWorkerTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSWorkerTableValues, 0 };
#else
    { 2, 1, JSWorkerTableValues, 0 };
#endif

/* Hash table for prototype */

static const HashTableValue JSWorkerPrototypeTableValues[3] =
{
    { "postMessage", DontDelete|Function, (intptr_t)static_cast<NativeFunction>(jsWorkerPrototypeFunctionPostMessage), (intptr_t)2 },
    { "terminate", DontDelete|Function, (intptr_t)static_cast<NativeFunction>(jsWorkerPrototypeFunctionTerminate), (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSWorkerPrototypeTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 15, JSWorkerPrototypeTableValues, 0 };
#else
    { 5, 3, JSWorkerPrototypeTableValues, 0 };
#endif

const ClassInfo JSWorkerPrototype::s_info = { "WorkerPrototype", 0, &JSWorkerPrototypeTable, 0 };

JSObject* JSWorkerPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSWorker>(exec, globalObject);
}

bool JSWorkerPrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticFunctionSlot<JSObject>(exec, &JSWorkerPrototypeTable, this, propertyName, slot);
}

bool JSWorkerPrototype::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticFunctionDescriptor<JSObject>(exec, &JSWorkerPrototypeTable, this, propertyName, descriptor);
}

const ClassInfo JSWorker::s_info = { "Worker", &JSAbstractWorker::s_info, &JSWorkerTable, 0 };

JSWorker::JSWorker(NonNullPassRefPtr<Structure> structure, JSDOMGlobalObject* globalObject, PassRefPtr<Worker> impl)
    : JSAbstractWorker(structure, globalObject, impl)
{
}

JSObject* JSWorker::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSWorkerPrototype(JSWorkerPrototype::createStructure(JSAbstractWorkerPrototype::self(exec, globalObject)));
}

bool JSWorker::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSWorker, Base>(exec, &JSWorkerTable, this, propertyName, slot);
}

bool JSWorker::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSWorker, Base>(exec, &JSWorkerTable, this, propertyName, descriptor);
}

JSValue jsWorkerOnmessage(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSWorker* castedThis = static_cast<JSWorker*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    Worker* imp = static_cast<Worker*>(castedThis->impl());
    if (EventListener* listener = imp->onmessage()) {
        if (const JSEventListener* jsListener = JSEventListener::cast(listener)) {
            if (JSObject* jsFunction = jsListener->jsFunction(imp->scriptExecutionContext()))
                return jsFunction;
        }
    }
    return jsNull();
}

void JSWorker::put(ExecState* exec, const Identifier& propertyName, JSValue value, PutPropertySlot& slot)
{
    lookupPut<JSWorker, Base>(exec, propertyName, value, &JSWorkerTable, this, slot);
}

void setJSWorkerOnmessage(ExecState* exec, JSObject* thisObject, JSValue value)
{
    UNUSED_PARAM(exec);
    Worker* imp = static_cast<Worker*>(static_cast<JSWorker*>(thisObject)->impl());
    imp->setOnmessage(createJSAttributeEventListener(exec, value, thisObject));
}

JSValue JSC_HOST_CALL jsWorkerPrototypeFunctionPostMessage(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSWorker::s_info))
        return throwError(exec, TypeError);
    JSWorker* castedThisObj = static_cast<JSWorker*>(asObject(thisValue));
    return castedThisObj->postMessage(exec, args);
}

JSValue JSC_HOST_CALL jsWorkerPrototypeFunctionTerminate(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSWorker::s_info))
        return throwError(exec, TypeError);
    JSWorker* castedThisObj = static_cast<JSWorker*>(asObject(thisValue));
    Worker* imp = static_cast<Worker*>(castedThisObj->impl());

    imp->terminate();
    return jsUndefined();
}

JSC::JSValue toJS(JSC::ExecState* exec, JSDOMGlobalObject* globalObject, Worker* object)
{
    return getDOMObjectWrapper<JSWorker>(exec, globalObject, object);
}
Worker* toWorker(JSC::JSValue value)
{
    return value.inherits(&JSWorker::s_info) ? static_cast<JSWorker*>(asObject(value))->impl() : 0;
}

}

#endif // ENABLE(WORKERS)
