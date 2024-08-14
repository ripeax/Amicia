#include "mem.h"
#include "wdm.h"
#include <winapi>


class win_kernel{
    win_kernel{

        NTSTATUS
    GetPCIBusInterfaceStandard(
        IN  PDEVICE_OBJECT DeviceObject,
        OUT PBUS_INTERFACE_STANDARD BusInterfaceStandard
    )
    {
        KEVENT event;
        NTSTATUS status;
        PIRP irp;
        IO_STATUS_BLOCK ioStatusBlock;
        PIO_STACK_LOCATION irpStack;
        PDEVICE_OBJECT targetObject;

        Bus_KdPrint(("GetPciBusInterfaceStandard entered.\n"));
        KeInitializeEvent(&event, NotificationEvent, FALSE);
        targetObject = IoGetAttachedDeviceReference(DeviceObject);
        irp = IoBuildSynchronousFsdRequest(IRP_MJ_PNP,
                                        targetObject,
                                        NULL,
                                        0,
                                        NULL,
                                        &event,
                                        &ioStatusBlock);
        if (irp == NULL) {
            status = STATUS_INSUFFICIENT_RESOURCES;
            goto End;
        }
        irpStack = IoGetNextIrpStackLocation( irp );
        irpStack->MinorFunction = IRP_MN_QUERY_INTERFACE;
        irpStack->Parameters.QueryInterface.InterfaceType = (LPGUID)&GUID_BUS_INTERFACE_STANDARD;
        irpStack->Parameters.QueryInterface.Size = sizeof(BUS_INTERFACE_STANDARD);
        irpStack->Parameters.QueryInterface.Version = 1;
        irpStack->Parameters.QueryInterface.Interface = (PINTERFACE)BusInterfaceStandard;
        irpStack->Parameters.QueryInterface.InterfaceSpecificData = NULL;

        irp->IoStatus.Status = STATUS_NOT_SUPPORTED;
        status = IoCallDriver(targetObject, irp);
        if (status == STATUS_PENDING) {
            KeWaitForSingleObject(&event, Executive, KernelMode, FALSE, NULL);
            status = ioStatusBlock.Status;
        }
    End:

        ObDereferenceObject(targetObject);
        return status;
    }


        PVOID PallocateCommonBuffer = alloc_buf(
            PDMA_ADAPTER Dma,
            ULONG len,
            PPHYSICAL_ADDRESS logical_addr,
            BOOLEAN CacheEnabled
        )
    }
    bytes = busInterfaceStandard.GetBusData(
                    busInterfaceStandard.Context,
                    PCI_WHICHSPACE_CONFIG,
                    Buffer
                    Offset,
                    Length);
}
